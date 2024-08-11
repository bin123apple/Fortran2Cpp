module c1107_mod
  implicit none
contains
  subroutine s1_c1107
  end subroutine s1_c1107

  subroutine s2_c1107
  end subroutine s2_c1107

  subroutine s3_c1107(x_in, x_out)
    integer, intent(in) :: x_in
    integer, intent(out) :: x_out
    x_out = x_in * 2
  end subroutine s3_c1107

  subroutine s4_c1107
  end subroutine s4_c1107

  subroutine s5_c1107(x, y)
    integer, intent(in) :: x
    integer, intent(out) :: y
    y = x * 2
  end subroutine s5_c1107

  subroutine s6_c1107
  end subroutine s6_c1107

  subroutine s7_c1107
  end subroutine s7_c1107
end module c1107_mod

program test_c1107
    use c1107_mod
    implicit none
    integer :: x_out_test, y_test

    call s1_c1107()
    print *, "s1_c1107 executed."

    call s2_c1107()
    print *, "s2_c1107 executed."

    call s3_c1107(5, x_out_test)
    print *, "s3_c1107 executed with x_out =", x_out_test

    call s4_c1107()
    print *, "s4_c1107 executed."

    call s5_c1107(10, y_test)
    print *, "s5_c1107 executed with y =", y_test

    call s6_c1107()
    print *, "s6_c1107 executed without arguments."

    call s7_c1107()
    print *, "s7_c1107 executed."
end program test_c1107