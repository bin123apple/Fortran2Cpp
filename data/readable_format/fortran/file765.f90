! test_modules.f90
program test_modules
  implicit none

contains

  subroutine f2pysetupfunc(test_double, test_complex)
    ! Dummy arguments to match the expected signature of f2pysetupfunc
    interface
      subroutine test_double()
      end subroutine
      subroutine test_complex()
      end subroutine
    end interface
    print *, "f2pysetupfunc for kinds_module called"
    call test_double()
    call test_complex()
  end subroutine f2pysetupfunc

  subroutine f2pysetupfunc_bhmie(bhmie_driver)
    interface
      subroutine bhmie_driver()
      end subroutine
    end interface
    print *, "f2pysetupfunc for bhmie_module called"
    call bhmie_driver()
  end subroutine f2pysetupfunc_bhmie

  subroutine f2pysetupfunc_dmiess(dmiess_driver)
    interface
      subroutine dmiess_driver()
      end subroutine
    end interface
    print *, "f2pysetupfunc for dmiess_module called"
    call dmiess_driver()
  end subroutine f2pysetupfunc_dmiess

  subroutine f2pysetupfunc_dmilay(dmilay_driver)
    interface
      subroutine dmilay_driver()
      end subroutine
    end interface
    print *, "f2pysetupfunc for dmilay_module called"
    call dmilay_driver()
  end subroutine f2pysetupfunc_dmilay

  ! Dummy implementations of the external subroutines
  subroutine test_double()
    print *, "test_double called"
  end subroutine test_double

  subroutine test_complex()
    print *, "test_complex called"
  end subroutine test_complex

  subroutine bhmie_driver()
    print *, "bhmie_driver called"
  end subroutine bhmie_driver

  subroutine dmiess_driver()
    print *, "dmiess_driver called"
  end subroutine dmiess_driver

  subroutine dmilay_driver()
    print *, "dmilay_driver called"
  end subroutine dmilay_driver

end program test_modules