! dft_setting_params.f90
program dft_setting_params_test
    implicit none

    ! Declare variables
    integer, parameter :: max_iter = 100
    real(kind=8), parameter :: conv_thresh = 1.0e-6
    logical :: print_info = .true.
    character(len=10) :: xc_functional

    ! Conditional compilation to set xc_functional
#ifdef __LIBXC
    xc_functional = 'PBE'
#else
    xc_functional = 'LDA'
#endif

    ! Test outputs
    print *, "Testing dft_setting_params settings..."
    print *, "max_iter =", max_iter
    print *, "conv_thresh =", conv_thresh
    print *, "print_info =", print_info
    print *, "xc_functional =", xc_functional

end program dft_setting_params_test