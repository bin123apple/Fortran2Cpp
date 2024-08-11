module mod_fin_04
  implicit none
  type :: p_vec
  contains
     final :: delete
  end type p_vec

  type, extends(p_vec) :: bar
  contains
    final :: del2
  end type bar
contains
  subroutine delete(this)
    type(p_vec) :: this
    print *, "p_vec final procedure called."
  end subroutine delete

  subroutine del2(this)
    type(bar) :: this
    print *, "bar final procedure called."
  end subroutine del2
end module mod_fin_04

program test_fin_04
    use mod_fin_04
    implicit none

    type(p_vec) :: a_p_vec
    type(bar) :: a_bar

    print *, "Creating and destroying a p_vec."
    a_p_vec = p_vec()

    print *, "Creating and destroying a bar."
    a_bar = bar()
end program test_fin_04