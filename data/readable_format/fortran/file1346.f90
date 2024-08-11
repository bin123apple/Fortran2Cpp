module multi_mod1
    integer :: a = 5
end module

module multi_mod2
    integer :: b = 10
end module

program test
    use multi_mod1
    use multi_mod2
    implicit none
    integer :: expected_a = 5
    integer :: expected_b = 10

    if (a == expected_a .and. b == expected_b) then
        print *, "Test passed: a and b have the expected values."
    else
        print *, "Test failed."
    end if
end program test