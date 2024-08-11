! test.f90
program test
  implicit none

  type :: concrete_type
    procedure(alloc_integer), pointer, nopass :: alloc
  end type

  procedure(alloc_integer), pointer :: pp

  type(concrete_type) :: concrete

  integer, allocatable :: direct_res, pp_res, concrete_res

  ! Test direct call
  direct_res = alloc_integer()
  if (.not. allocated(direct_res) .or. direct_res /= 13) then
     print *, 'Direct call test failed.'
  else
     print *, 'Direct call test passed.'
  endif

  ! Test function pointer call
  pp => alloc_integer
  pp_res = pp()
  if (.not. allocated(pp_res) .or. pp_res /= 13) then
     print *, 'Function pointer call test failed.'
  else
     print *, 'Function pointer call passed.'
  endif

  ! Test concrete type function pointer call
  concrete % alloc => alloc_integer
  concrete_res = concrete % alloc()
  if (.not. allocated(concrete_res) .or. concrete_res /= 13) then
     print *, 'Concrete type function pointer call test failed.'
  else
     print *, 'Concrete type function pointer call passed.'
  endif

contains

   function alloc_integer() result(res)
      integer, allocatable :: res
      allocate(res, source=13)
   end function

end program test