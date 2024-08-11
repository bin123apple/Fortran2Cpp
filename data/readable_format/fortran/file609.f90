module inversionGrid
  implicit none
  save

  type :: inversion_grid
    ! Add members of inversion_grid here
    logical :: is_initialized = .false.
  end type inversion_grid

  contains

    subroutine initialize_grid(grid)
      type(inversion_grid), intent(inout) :: grid
      grid%is_initialized = .true.
    end subroutine initialize_grid

end module inversionGrid

module errorMessage
  implicit none
  save

  type :: error_message
    ! Add members of error_message here
    logical :: has_error = .false.
  end type error_message

  contains

    subroutine set_error(msg, hasError)
      type(error_message), intent(inout) :: msg
      logical, intent(in) :: hasError
      msg%has_error = hasError
    end subroutine set_error

end module errorMessage

module create_shore_lines_f2pyVar
  use inversionGrid
  use errorMessage
  implicit none
  save

  type (inversion_grid) :: invgrid
  type (error_message) :: errmsg

  logical :: invgrid_created = .false.

end module create_shore_lines_f2pyVar

program test
  use create_shore_lines_f2pyVar
  implicit none

  call initialize_grid(invgrid)
  call set_error(errmsg, .true.)

  if (.not. invgrid_created) then
    print *, "invgrid_created is initially .false."
  else
    print *, "invgrid_created is not .false. (Error)"
  endif

  if (invgrid%is_initialized) then
    print *, "invgrid is initialized."
  else
    print *, "invgrid is not initialized. (Error)"
  endif

  if (errmsg%has_error) then
    print *, "errmsg has an error."
  else
    print *, "errmsg does not have an error. (Error)"
  endif
end program test