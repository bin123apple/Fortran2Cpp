module panel_utilities
  implicit none
contains
  logical function Panel_Diagonal(Ilo, Ihi, Jlo, Jhi, Dlo, Dhi)
    integer, intent(in) :: Ilo, Ihi, Jlo, Jhi
    integer, intent(out) :: Dlo, Dhi
    integer :: UR, LL

    UR = Ihi - Jlo
    LL = Ilo - Jhi

    if (UR * LL > 0) then
      Panel_Diagonal = .false.
      return
    else
      Panel_Diagonal = .true.
    endif

    Dlo = max(Ilo, Jlo)
    Dhi = min(Ihi, Jhi)
  end function Panel_Diagonal
end module panel_utilities

program TestPanelDiagonal
  use panel_utilities
  implicit none
  logical :: Result
  integer :: Dlo, Dhi

  ! Test Case 1
  Result = Panel_Diagonal(1, 5, 2, 6, Dlo, Dhi)
  call PrintResults(Result, Dlo, Dhi)

  ! Test Case 2
  Result = Panel_Diagonal(3, 7, 1, 4, Dlo, Dhi)
  call PrintResults(Result, Dlo, Dhi)

  ! Test Case 3
  Result = Panel_Diagonal(4, 8, 5, 9, Dlo, Dhi)
  call PrintResults(Result, Dlo, Dhi)

contains
  subroutine PrintResults(Result, Dlo, Dhi)
    logical, intent(in) :: Result
    integer, intent(in) :: Dlo, Dhi

    if (Result) then
      print *, "Panel Diagonal Test: Pass, Dlo=", Dlo, "Dhi=", Dhi
    else
      print *, "Panel Diagonal Test: Fail"
    endif
  end subroutine PrintResults
end program TestPanelDiagonal