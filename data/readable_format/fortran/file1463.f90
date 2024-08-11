module chanel_C 
    ! Assuming vast_kind_param provides a kind parameter for double precision
    integer, parameter :: dp = kind(1.0d0)

    integer ::       iw = 26
    integer :: &
        ifiles_1 = 1, &
        input = 2, &
        iscr = 3, &
        irot = 2, &
        iend = 4, &
        ir = 25, &
        iferr = 8, &
        ires = 9, &
        iden = 10, &
        ilog = 31, &
        iarc = 12, &
        igpt = 13, &
        iext = 14, &
        iesr = 15, &
        isyb = 16, &
        isol = 17, &
        ibrz = 18, &
        ipdb = 19, &
        iump = 20, &
        iesp = 21, &
        imep = 22, &
        param_out = 24, &
        isetup = 27, &
        lbfgs_it = 28, &
        idaf = 29, &
        is = 30

    integer, parameter :: filename_len = 240

    character(len=filename_len) :: &
        job_fn, &
        output_fn, &
        restart_fn, &
        density_fn, &
        log_fn, &
        end_fn, &
        ext_fn, &
        archive_fn

    integer, dimension(145) :: ifilen, ioda 
    integer :: irecln = 1023, irecst 
end module chanel_C

program test_chanel_C
    use chanel_C
    implicit none

    ! Your testing code here
    write(*,*) 'Testing module chanel_C'
    write(*,*) 'iw = ', iw
    ! Add any additional tests or use cases here
end program test_chanel_C