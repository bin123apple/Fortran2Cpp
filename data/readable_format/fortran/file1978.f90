! Test Program for Fortran example
PROGRAM testSubarray

    character *7 str
    integer array(7), i

    str = 'abcdefg'
    do i = 1, 7
      array(i) = i
    end do

    ! Test outputs manually
    write (*, *) str(2:4)
    write (*, *) str(:3)
    write (*, *) str(5:)
    write (*, *) str(:)

    ! Simple check for array content
    do i = 1, 7
      if (array(i) /= i) then
        write(*,*) "Test failed for array initialization."
        stop
      endif
    end do
    write(*,*) "Array initialization test passed."

END PROGRAM testSubarray