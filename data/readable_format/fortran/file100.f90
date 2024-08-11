module m_work_4_sph_trans_spin

  ! Assuming kreal is equivalent to double precision
  ! Assuming kint is equivalent to integer
  implicit none
  double precision, allocatable :: vr_rtm_wk(:)
  double precision, allocatable :: sp_rlm_wk(:)

  ! Simplified parameters
  integer, parameter :: kreal = selected_real_kind(p=8)
  integer, parameter :: kint = selected_int_kind(8)
  integer, parameter :: nnod_rlm = 10
  integer, parameter :: nnod_rtm = 20

contains

  subroutine allocate_work_sph_trans(ncomp)
    integer(kind = kint), intent(in) :: ncomp

    allocate(sp_rlm_wk(nnod_rlm*ncomp))
    allocate(vr_rtm_wk(nnod_rtm*ncomp))

    call clear_bwd_legendre_work(ncomp)
    call clear_fwd_legendre_work(ncomp)
  end subroutine allocate_work_sph_trans

  subroutine deallocate_work_sph_trans
    deallocate(vr_rtm_wk, sp_rlm_wk)
  end subroutine deallocate_work_sph_trans

  subroutine clear_fwd_legendre_work(ncomp)
    integer(kind = kint), intent(in) :: ncomp
    if(ncomp <= 0) return
    sp_rlm_wk(1:nnod_rlm*ncomp) = 0.0d0
  end subroutine clear_fwd_legendre_work

  subroutine clear_bwd_legendre_work(ncomp)
    integer(kind = kint), intent(in) :: ncomp
    if(ncomp <= 0) return
    vr_rtm_wk(1:nnod_rtm*ncomp) = 0.0d0
  end subroutine clear_bwd_legendre_work

end module m_work_4_sph_trans_spin

program test_work_4_sph_trans_spin
  use m_work_4_sph_trans_spin
  implicit none

  integer, parameter :: test_ncomp = 5
  integer :: i

  call allocate_work_sph_trans(test_ncomp)
  print *, 'Allocated work arrays.'

  if (allocated(sp_rlm_wk) .and. allocated(vr_rtm_wk)) then
      print *, 'Allocation test passed.'
  else
      print *, 'Allocation test failed.'
  end if

  sp_rlm_wk = 1.0  ! For simplicity, assuming this doesn't violate any logic
  call clear_fwd_legendre_work(test_ncomp)
  if (all(sp_rlm_wk == 0.0d0)) then
      print *, 'Clear forward work passed.'
  else
      print *, 'Clear forward work failed.'
  end if

  call deallocate_work_sph_trans
  print *, 'Deallocated work arrays.'
end program test_work_4_sph_trans_spin