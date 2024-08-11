module save_in_electrons_mod
    implicit none
    integer, parameter :: dp = kind(1.0d0)
contains
    subroutine save_in_electrons(iter, dr2)
        integer, intent(in) :: iter
        real(dp), intent(in) :: dr2
        integer :: iunres
        real(dp) :: etot, tr2, ethr
        real(dp), dimension(2,2) :: et
        real(dp), dimension(3) :: vnew
        logical :: conv_elec
        character(len=20) :: where

        ! Mock conditions
        iunres = 10
        etot = 100.0_dp
        tr2 = 1.0_dp
        ethr = 0.5_dp
        et = reshape([1.0_dp, 2.0_dp, 3.0_dp, 4.0_dp], [2, 2])
        vnew = [0.1_dp, 0.2_dp, 0.3_dp]
        conv_elec = .true.

        ! Logic for save_in_electrons (simplified)
        if (conv_elec) then
            where = 'IONS'
            print *, where
            print *, et
            print *, etot, tr2
            print *, vnew
        else
            where = 'ELECTRONS'
            print *, where
        endif
    end subroutine save_in_electrons
end module save_in_electrons_mod

program test
    use save_in_electrons_mod
    call save_in_electrons(1, 0.25_dp)
end program test