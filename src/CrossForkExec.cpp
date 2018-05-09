//CrossForkExec.cpp
//Author: Sivert Andresen Cubedo

#include "../include/CrossForkExec.hpp"

namespace CrossForkExec
{
#ifdef WINDOWS
	ChildProcess::ChildProcess(const PROCESS_INFORMATION & pi) :
		m_process_information(pi)
	{
	}

	void ChildProcess::join()
	{
		WaitForSingleObject(m_process_information.hProcess, INFINITE);
	}

	void ChildProcess::close()
	{
		CloseHandle(m_process_information.hProcess);
		CloseHandle(m_process_information.hThread);
	}

	ChildProcess forkExec(const std::string & program_path, const std::vector<std::string> & program_args)
	{
		STARTUPINFO startup_info;
		std::memset(&startup_info, 0, sizeof(STARTUPINFO));
		PROCESS_INFORMATION process_information;
		std::memset(&process_information, 0, sizeof(PROCESS_INFORMATION));

		std::ostringstream cmd_stream;
		cmd_stream << program_path;
		for (std::string s : program_args) {
			cmd_stream << " " << s;
		}

		std::string cmd_string = cmd_stream.str();
		std::size_t len = cmd_string.length() + 1; //+1 for \0
		
		LPSTR cmd = (LPSTR)std::malloc(len);	
		if (cmd == NULL) {
			throw std::runtime_error("forkExec: std::malloc()");
		}

		strncpy_s(cmd, len, cmd_string.c_str(), len);

		if (!CreateProcess(
			NULL,
			cmd,
			NULL,
			NULL,
			TRUE,
			0,
			NULL,
			NULL,
			&startup_info,
			&process_information
		)) {
			throw ErrorProcessException(GetLastError());
		}

		free(cmd);

		return ChildProcess(process_information);
	}

#elif LINUX

#endif
}