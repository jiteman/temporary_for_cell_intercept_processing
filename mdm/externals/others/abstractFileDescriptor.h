#pragma once


#include "checkKeyStruct.h"

#include "jmsf/stdal/stdal_stl.h"
#include "temporary_windows_include.h"


// ��������� ���� ������
enum _FileType {_FTC = 1, _SDC, _RTC, _INI, _INVALID};

struct FileDescriptorData
{
    _FileType type;
    std::string fileName;     // ���, ��� ����������
    FILETIME creationTime;    // ����� ��������, �������� � �����
    FILETIME creationTimeIni; // ����� �������� �����, ���������� �� ini �����
    
    std::string appenderWorkFolder;

    std::string longPath;     // ���� � �����, ������� � ����� �����

    std::string network;
    std::string baseStation;

	unsigned int networkAndBaseStationId;

    unsigned int R1, R2, R3; // decipher key

    std::string temporaryNumber;

    FILETIME addFileTime;

    BOOL isSMS;
	BOOL isSMSSussesfullSent;
	BOOL isStatisticsAlreadyPassed;
	unsigned int donePercent;

#ifdef _FULL_DEBUG_LOG
    std::list< std::string > _logMessages;
#endif                      	
};

struct AppliedData {
    //BYTE *dataAfterApplyKey;
    std::vector< BYTE > dataAfterApplyKey;
	int tch_duration;
    tTCHHandle tchData;
    tSDCCHHandle sdcData;

};


bool compareFileDescriptorTime( const FileDescriptorData *first, const FileDescriptorData *second );
