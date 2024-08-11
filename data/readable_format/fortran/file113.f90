module mpoint
  ! As before
  type           ::       mytype
    integer      ::       i
  end type mytype

contains

  ! Functions as before
  function get (a) result (b)
    type (mytype), target   ::      a
    type (mytype), pointer  ::      b
    b => a
  end function get

  function get2 (a)
    type (mytype), target   ::      a
    type (mytype), pointer  ::      get2
    get2 => a
  end function get2

end module mpoint

program func_derived_2
  use mpoint
  implicit none
  type (mytype), target  ::       x
  type (mytype), pointer ::       y

  ! Test get function
  x = mytype (42)
  y => get (x)
  if (y%i == 42) then
    print *, "Test get passed."
  else
    print *, "Test get failed."
    call abort ()
  end if

  ! Test get2 function
  x = mytype (112)
  y => get2 (x)
  if (y%i == 112) then
    print *, "Test get2 passed."
  else
    print *, "Test get2 failed."
    call abort ()
  end if
end program func_derived_2