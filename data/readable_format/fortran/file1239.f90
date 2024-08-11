! Assuming the function returns the sum of its two arguments
function great_rsd(a, b)
    real :: a
    real :: b
    real :: great_rsd
    
    great_rsd = a + b
end function great_rsd

program test_great_rsd
    real :: result
    
    ! Test case 1
    result = great_rsd(1.0, 2.0)
    if (result == 3.0) then
        print *, "Test 1 Passed"
    else
        print *, "Test 1 Failed"
    end if
    
    ! Add more tests as necessary
end program test_great_rsd