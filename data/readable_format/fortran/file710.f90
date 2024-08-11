module M1
contains
  integer function G1()
    G1 = 1
  end function G1

  integer function G2()
    G2 = 1
  end function G2

  integer function G3()
    G3 = 1
  end function G3
end module M1

program Test
  use M1
  implicit none
  
  ! Test functions from module M1
  write(*,*) 'Testing G1 from M1:', G1()
  write(*,*) 'Testing G2 from M1:', G2()
  write(*,*) 'Testing G3 from M1:', G3()
  
  ! Test functions defined within the program
  write(*,*) 'Testing F1:', F1()
  write(*,*) 'Testing F2:', F2()

contains

  integer function F1()
    F1 = 1
  end function F1

  integer function F2()
    F2 = 1
  end function F2

end program Test