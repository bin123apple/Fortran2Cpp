program test_prog
    dimension expected(4), output_vals(4)
    common /val_comm/ output_vals

    call prog

    expected(1) = 1.2
    expected(2) = expected(1)**2
    expected(3) = 2**expected(2)
    expected(4) = expected(2)**expected(3)

    do i = 1, 4
        if (abs(expected(i) - output_vals(i)) > 1.0e-6) then
            print *, "Test failed at index", i
            stop
        endif
    end do

    print *, "All tests passed."
end program test_prog

subroutine prog
    dimension vals(4)
    common /val_comm/ vals

    vals(1) = 1.2
    vals(2) = vals(1)**2
    vals(3) = 2**vals(2)
    vals(4) = vals(2)**vals(3)

    write(6, '(4f5.2)') (vals(i), i=1,4)
end subroutine prog