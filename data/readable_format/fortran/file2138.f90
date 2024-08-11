module formats

character(len=30) :: OFMT1   = "(3E30.16E3)",&   
     OFMT2   = "(34E30.16E3)",&  
     OFMT3   = "(7E30.16E3)",&  
     OFMT4   = "(7E30.16E3)",&  
     OFTM44  = "(66E30.16E3)",& 
     OFMT71  = "(71E30.16E3)"   

end module formats

program test_formats
    use formats
    implicit none

    call verify_format(OFMT1, "(3E30.16E3)")
    call verify_format(OFMT2, "(34E30.16E3)")
    call verify_format(OFMT3, "(7E30.16E3)")
    call verify_format(OFMT4, "(7E30.16E3)")
    call verify_format(OFTM44, "(66E30.16E3)")
    call verify_format(OFMT71, "(71E30.16E3)")

contains

    subroutine verify_format(actual, expected)
        character(len=*), intent(in) :: actual, expected
        if (trim(actual) /= expected) then
            print *, "Test failed: expected ", expected, " but got ", actual
        else
            print *, "Test passed: ", actual
        end if
    end subroutine verify_format

end program test_formats