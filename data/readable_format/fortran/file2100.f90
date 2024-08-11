program test_version_function
    implicit none
    character(len=5) :: expected_version
    character(len=5) :: result

    interface
        character(len=5) function version()
        end function version
    end interface

    expected_version = '2.2.1'
    result = version()

    print *, 'Testing version function...'
    if (trim(result) == trim(expected_version)) then
        print *, 'Test passed.'
    else
        print *, 'Test failed.'
    end if
end program test_version_function

character(len=5) function version()
    version = '2.2.1'
end function version