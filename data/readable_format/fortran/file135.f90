module lib
  implicit none

  integer :: i
  integer :: mpi_err, req_recv, req_send
  type Kozo
     double precision, dimension(42) :: U
     double precision, dimension(42) :: V     
  end type Kozo

  type(Kozo) :: Iriguchi
  type(Kozo) :: Deguchi

end module lib

program test_lib
    use lib
    implicit none

    ! Initialize some values
    Iriguchi%U = 1.0
    Iriguchi%V = 2.0
    Deguchi%U = 3.0
    Deguchi%V = 4.0

    ! Print values to verify
    print *, "Iriguchi%U(1):", Iriguchi%U(1)
    print *, "Iriguchi%V(1):", Iriguchi%V(1)
    print *, "Deguchi%U(1):", Deguchi%U(1)
    print *, "Deguchi%V(1):", Deguchi%V(1)

end program test_lib