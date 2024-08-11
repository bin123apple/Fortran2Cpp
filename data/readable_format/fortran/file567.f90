module para
contains
   function bobo(n)
       integer, intent(in) :: n
       character(len=n) :: bobo
       bobo = "1234567890"(1:n)
   end function bobo
end module para

program test
    use para
    implicit none
    character(len=10) :: result
    
    ! Test 1
    result = bobo(10)
    if (result /= "1234567890") then
        print *, "Test 1 failed: Expected 1234567890, got ", result
        stop 1
    end if

    ! Test 2
    result = bobo(5)
    if (result(1:5) /= "12345") then
        print *, "Test 2 failed: Expected 12345, got ", result(1:5)
        stop 1
    end if

    ! Test 3
    result = bobo(0)
    if (trim(result) /= "") then
        print *, "Test 3 failed: Expected an empty string, got '", trim(result), "'"
        stop 1
    end if

    print *, "All tests passed!"
end program test