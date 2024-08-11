module m_tenstr_rrsw_aer

  implicit none
  save

  ! Assuming kind_rb is equivalent to 8-byte real
  integer, parameter :: kind_rb = selected_real_kind(15, 307)
  ! Assuming these constants based on your usage
  integer, parameter :: nbndsw = 10, naerec = 5

  real(kind=kind_rb) :: rsrtaua(nbndsw,naerec)
  real(kind=kind_rb) :: rsrpiza(nbndsw,naerec)
  real(kind=kind_rb) :: rsrasya(nbndsw,naerec)

end module m_tenstr_rrsw_aer

program test_m_tenstr_rrsw_aer
  use m_tenstr_rrsw_aer
  implicit none

  integer :: i, j
  real(kind=kind_rb) :: test_val

  ! Initialize test value
  test_val = 123.456_kind_rb

  ! Modify arrays
  do i = 1, nbndsw
    do j = 1, naerec
      rsrtaua(i, j) = test_val
      rsrpiza(i, j) = test_val + 1.0_kind_rb
      rsrasya(i, j) = test_val + 2.0_kind_rb
    end do
  end do

  ! Check modifications
  do i = 1, nbndsw
    do j = 1, naerec
      if (rsrtaua(i, j) /= test_val .or. &
          rsrpiza(i, j) /= test_val + 1.0_kind_rb .or. &
          rsrasya(i, j) /= test_val + 2.0_kind_rb) then
        print *, "Test failed for element:", i, j
        stop
      end if
    end do
  end do

  print *, "Fortran test passed successfully."
end program test_m_tenstr_rrsw_aer