program test_tt
    type tt
        integer a
        double precision b
        character(len=10) c
    end type tt

    type(tt)::a
    data a /tt(1, 2.0D1, "ccc")/

    if (a%a == 1 .and. a%b == 20.0D0 .and. trim(a%c) == "ccc") then
        print *, "Test passed: tt initialized correctly"
    else
        print *, "Test failed: tt not initialized as expected"
    endif
end program test_tt