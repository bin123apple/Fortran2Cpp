program test_format
    implicit none
    integer :: unit_number

    open(newunit=unit_number, file='fortran_output.txt', status='replace', action='write')

    write(unit_number,'(I4,T8,I1)') 1234,8
    write(unit_number,'(I4,TR3,I1)') 1234,8
    write(unit_number,'(I4,5X,TL2,I1)') 1234,8

    close(unit_number)
end program test_format