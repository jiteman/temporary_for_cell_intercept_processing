#pragma once

#include "jmsf/stdal/stdal_stl.h"

struct LogFile {
    std::ofstream _logFile;

    void openLog( const std::string & ) { // folderName
        // ����� ������� ������� ����� ��������
        // ������� � ��� ����� � ������ ������
        // ������� � ��� ���� ���� � ����������� Id ������
    }

    void closeLog() {
        if( _logFile.is_open() ) {
            _logFile.flush();
            _logFile.close();
        }
    }

    void dump( const std::string &data ) {
        if( _logFile.is_open() )
            _logFile << data << std::endl;
    }

private:
	LogFile( const LogFile &other ) throw();
	const LogFile &operator =( const LogFile &other ) throw();

};

LogFile *createLog();
void deleteLog( LogFile *logFile );