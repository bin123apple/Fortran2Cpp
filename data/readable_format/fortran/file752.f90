program test_name_database_integration
  implicit none
  ! Define the constant directly in the program
  integer, parameter :: MAX_STRING_LEN = 256
  character(len=MAX_STRING_LEN) :: prname
  character(len=MAX_STRING_LEN) :: LOCAL_PATH
  integer :: iproc, iregion_code

  ! Sample values for demonstration
  LOCAL_PATH = "/example/path"
  iproc = 123456
  iregion_code = 7

  ! Test create_name_database
  call create_name_database(prname, iproc, iregion_code, LOCAL_PATH)
  print *, "Test create_name_database: ", prname

  ! Test create_name_database_adios
  call create_name_database_adios(prname, iregion_code, LOCAL_PATH)
  print *, "Test create_name_database_adios: ", prname

contains

  subroutine create_name_database(prname, iproc, iregion_code, LOCAL_PATH)
    integer, intent(in) :: iproc, iregion_code
    character(len=*), intent(in) :: LOCAL_PATH
    character(len=MAX_STRING_LEN), intent(out) :: prname
    character(len=MAX_STRING_LEN) :: procname
    write(procname,"('/proc',i6.6,'_reg',i1,'_')") iproc, iregion_code
    prname = trim(LOCAL_PATH) // procname
  end subroutine create_name_database

  subroutine create_name_database_adios(prname, iregion_code, LOCAL_PATH)
    integer, intent(in) :: iregion_code
    character(len=*), intent(in) :: LOCAL_PATH
    character(len=MAX_STRING_LEN), intent(out) :: prname
    character(len=MAX_STRING_LEN) :: procname
    write(procname,"('/reg',i1,'_')") iregion_code
    prname = trim(LOCAL_PATH) // procname
  end subroutine create_name_database_adios

end program test_name_database_integration