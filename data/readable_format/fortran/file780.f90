program test_nutest
    implicit none
    integer :: ios
    logical :: l

    ! Test file creation and deletion
    open(unit=100, file="test_file.txt", status="replace", action="write", iostat=ios)
    if (ios /= 0) then
        print *, "Failed to open test_file.txt for writing."
        stop 1
    endif
    close(100, status="delete")

    ! Check if file deletion was successful
    inquire(file="test_file.txt", exist=l)
    if (l) then
        print *, "Failed to delete test_file.txt."
        stop 1
    endif

    print *, "Fortran unit tests passed."
end program test_nutest