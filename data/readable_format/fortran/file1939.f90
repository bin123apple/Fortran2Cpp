program file_existence_check
    implicit none
    logical :: file_exists

    inquire(file='test_file.txt', exist=file_exists)
    if (file_exists) then
        print *, 'File exists.'
    else
        print *, 'File does not exist.'
    end if
end program file_existence_check