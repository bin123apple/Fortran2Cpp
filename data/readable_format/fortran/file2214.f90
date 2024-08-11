program test_enq_v2_path_comp
    implicit none
    real*8 pc_ra, pc_dec
    integer s

    ! External subroutine
    call enq_v2_path_comp(pc_ra, pc_dec, 0)

    print *, 'pc_ra: ', pc_ra
    print *, 'pc_dec: ', pc_dec

contains

    subroutine enq_v2_path_comp(pc_ra, pc_dec, s)
        real*8          pc_ra, pc_dec
        integer         s

        real*8          RAdate, DECdate
        parameter (RAdate = 123.456, DECdate = 78.9)

        if (s.ne.0) return

        pc_ra  = RAdate
        pc_dec = DECdate

        if (s.ne.0) then
            call smp_wrerr(s, 'in subroutine enq_v2_path_comp.')
        endif
    end subroutine enq_v2_path_comp

    subroutine smp_wrerr(s, message)
        integer s
        character*(*) message
        print *, 'Error', s, ':', message
    end subroutine smp_wrerr

end program test_enq_v2_path_comp