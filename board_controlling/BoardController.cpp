#include "BoardController.h"


namespace nppntt {
namespace board_controlling {


void append() throw() {
// 	while ( _terminated.not() ) {
// 		Task := 2;
// 
// 		{ Disk FIFO }
// 		if ���� ������� �� ������ then
// 		begin
// 			!!! ���������, ����� �� �������� � ���� �������� !!!
// 
//       		if �� ����� then
//     		begin
// 				!!! �������� ������ !!!
// 			end
//     		else
//     		begin
// 
//         		!!! ��� �������� ����������� ������ ������ � �����. ��� �� ��� ��������� ������ �� ����� !!!
//         		ToPlata(true, Pfx, fromDisk.Session.nN, fromDisk.Session.bN, finish, fromDisk.RANDS, fromDisk.WorkAlpha, fromDisk.FinCnt);
// 
// 
//         		!!! ��������� ����������� ������ ����� !!!
// 
//         		if �� ��������� ������� ������ then
// 					!!! �������� ������� � ���������� ������. �� ����������: (������ �����������)/(�� �����������) !!!
// 
//         		if ������ ����������� then
//         		begin
// 					!!! ��������� SessionID ������� ������� � ������ �� ���������� !!!
//         		end
// 
//         		if ��� ��������� ������� then
//         		begin
// 					!!! �������� ������� � ���������� ������, � ���������� (��� ������ �������) !!!
// 				end;
//       		end;
// 		end;
// 
// 		{ Gamma FIFO }
// 		if ���� ������� �� ����� then
// 		begin
// 			!!! ���������, ����� �� �������� � ���� �������� !!!
// 
// 	  		if �� ����� then
// 			begin
//         		!!! �������� ������ !!!
//       		end
//       		else
// 			begin
// 				!!! ��� �������� ������� �� ����� � �����. ��� �� ��� ��������� ������ �� ����� !!!
//         		ToPlata(false, Pfx, fromGamma.nN, fromGamma.bN, toDisk.FINISH, toDisk.RANDS, toDisk.WorkAlpha, FinCnt);
// 				!!! ���������� ������� � ������� ��������� ������ !!!
// 			end;
// 		end;
// 
// 		{ ������ }
// 		if ��� ������� then
// 		begin
//     		if ��������� ������� ������ then
//       		begin
//         		!!! ���������� ������, �������� ������� !!!
//       		end;
// 		end;
// 	} // while
// 
// 
// 	����� ���������� � �������:
// 
// 	while Not Terminated do
// 	begin
// 
// 		if ���� ������� �� ����� then
// 		begin
// 			!!! ���������, ����� �� �������� � ���� �������� !!!
// 
// 			if �� ����� then
// 			begin
// 				!!! �������� ������ !!!
// 			end
// 			else
// 			begin
// 				!!! ����������� ������ ��� SssdInterface_readData !!!
// 
// 				// SSD DLL
// 				FillChar(FinishToSSD, Sizeof(FinishToSSD), 0);
// 				FillChar(RandsToSSD, Sizeof(RandsToSSD), 0);
// 				FillChar(AlphaToSSD, Sizeof(AlphaToSSD), 0);
// 				FillChar(RandData, sizeof(RandData), 0);
// 
// 				for i := 0 to fromPlis.Session.nN - 1 do
// 				begin
// 					toPlis.WorkAlpha[i] := fromPlis.WorkAlpha[i];
// 					for j := 0 to AriaParams.XORCount - 1 do
// 					begin
// 							arrayIndex := i * AriaParams.XORCount + j;
// 							if (fromPlis.FINISH[arrayIndex] <> 0) then
// 							begin
// 									FinishToSSD[arrayIndex] := fromPlis.FINISH[arrayIndex];
// 									RandsToSSD[arrayIndex] := RandToXOR(fromPlis.RANDS[arrayIndex]) or (Int64(i) shl RANDSaveParams.START_LenShift);
// 									AlphaToSSD[arrayIndex] := fromPlis.WorkAlpha[i];
// 							end;
// 					end;
// 				end;
// 
// 				if (@SssdInterface_readData <> nil) then
//             		SssdInterface_readData(16384, @RandData, fromPlis.Session.nN * AriaParams.XORCount, @FinishToSSD, @AlphaToSSD, @RandsToSSD);
// 
// 				!!! ���������� ��������� !!!
// 				for j := 0 to 16384 - 1 do
// 				begin
// 					if RandData[ j ] = 0 then break;
// 					ChipID:=RandData[j] shr RANDSaveParams.START_LenShift;
// 					toPlis.RANDS[toPlis.FinCnt[ChipID]+4096*ChipID]:=RandData[j] and RANDSaveParams.START_LenEraserMask;
// 					Inc(toPlis.FinCnt[ChipID]);
// 				end;
// 
//     			!!! �������� ������� � ������� ����� !!!
// 			end;
// 		end
// 		else
// 		begin
//     		if ��������� ������� ������ then
// 			begin
// 				!!! ���������� ������, �������� ������� !!!
// 			end;
// 		end;
// 	end; // end while
}


void BoardController::appendPrefix( ::jmsf::UniquePointer< data_Prefix > prefix ) throw() {
	_prefixQueue->appendBack( prefix );
}

::jmsf::UniquePointer< data_Register > BoardController::getRegister() throw() {
	return _registerQueue->takeFirst();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
BoardController::~BoardController() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::UniquePointer< BoardController > BoardController::create() throw() {
	return ::jmsf::UniquePointer< BoardController >( new BoardController );
}

BoardController::BoardController() throw()
	:
		_prefixQueue( SynchronizedQueue< data_Prefix >::create( ::jmsf::osie::runup::Mutex::create() ) ),
		_finishQueue( SynchronizedQueue< data_Finish >::create( ::jmsf::osie::runup::Mutex::create() ) ),
		_randQueue( SynchronizedQueue< data_Rand >::create( ::jmsf::osie::runup::Mutex::create() ) ),
		_registerQueue( SynchronizedQueue< data_Register >::create( ::jmsf::osie::runup::Mutex::create() ) )
{
	_prefixToFinishProcessingChannel = PrefixToFinishProcessingChannel::create( _prefixQueue, _finishQueue );
	_finishToRandProcessingChannel = FinishToRandProcessingChannel::create( _finishQueue, _randQueue );
	_randToRegisterProcessingChannel = RandToRegisterProcessingChannel::create( _randQueue, _registerQueue );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::UniquePointer< BoardController > BoardController::createClone() const throw() {
	return ::jmsf::UniquePointer< BoardController >( new BoardController( *this ) );
}

BoardController::BoardController( const BoardController & ) throw() // other
{}

const BoardController &BoardController::operator =( const BoardController &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
