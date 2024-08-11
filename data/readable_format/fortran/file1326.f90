module m
  type t
  end type t
end module m

program test
    use m
    type(t) :: obj
    print*, "Fortran test passed."
end program test