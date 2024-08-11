program test_mod_pdf
  implicit none
  real(kind=8) :: x, mu, sigma
  integer :: i

  ! Testing norm_pdf
  print *, 'Testing norm_pdf'
  print *, 'norm_pdf(0, 0, 1) =', norm_pdf(0.0d0, 0.0d0, 1.0d0)
  print *, 'norm_pdf(1, 0, 1) =', norm_pdf(1.0d0, 0.0d0, 1.0d0)

  ! Testing randn_box_muller
  mu = 0.0d0
  sigma = 1.0d0
  print *, 'Testing randn_box_muller'
  do i = 1, 5
     call randn_box_muller(x, mu, sigma)
     print *, 'Sample ', i, ': ', x
  end do

contains

  subroutine randn_box_muller(x, mu, sigma)

    real(kind=8), intent(out) :: x
    real(kind=8), intent(in)  :: mu, sigma
    logical, save             :: have_second_sample = .false.
    real(kind=8), save        :: saved_sample
    real(kind=8)              :: myrand1, myrand2, v1, v2, rsq, fac

    if (.not. have_second_sample) then
      do
        call random_number(myrand1)
        call random_number(myrand2)
        v1 = 2.0d0*myrand1 - 1.0d0
        v2 = 2.0d0*myrand2 - 1.0d0

        rsq = v1*v1 + v2*v2
        if (rsq < 1.0d0 .and. rsq /= 0.0d0) exit
      end do

      fac = sqrt(-2.0d0*log(rsq)/rsq)
      saved_sample = v1*fac*sigma + mu
      x = v2*fac*sigma + mu

      have_second_sample = .true.
    else
      x = saved_sample
      have_second_sample = .false.
    end if

  end subroutine randn_box_muller

  elemental function norm_pdf(x, mean, variance) result (y)
    real(kind=8), intent(in) :: x, mean, variance
    real(kind=8)             :: y
    real(kind=8), parameter  :: pi = 3.14159265358979323846d0

    y = 1.0d0 / (sqrt(variance * 2.0d0 * pi)) * exp( -(x - mean)**2 / (2.0d0 * variance))
  end function norm_pdf

end program test_mod_pdf