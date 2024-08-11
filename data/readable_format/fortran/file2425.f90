module modA
contains
  subroutine subA()
    print *, "subA is called"
  end subroutine subA
end module modA

program testModA
  use modA
  call subA()
end program testModA