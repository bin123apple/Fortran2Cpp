module MFAnimal
  implicit none
  private
  public :: TFAnimal

  type, abstract :: TFAnimal
  contains
    procedure(say_interface), deferred, pass(self) :: say
  end type TFAnimal

  interface
    function say_interface(self)
      import :: TFAnimal
      class(TFAnimal), intent(in) :: self
      character(len=80) :: say_interface
    end function say_interface
  end interface
end module MFAnimal

module MFCat
  use MFAnimal
  implicit none
  private
  public :: TFCat

  type, extends(TFAnimal) :: TFCat
  contains
    procedure :: say => say_cat
  end type TFCat

contains
  function say_cat(self)
    class(TFCat), intent(in) :: self
    character(len=80) :: say_cat
    say_cat = 'Myaw'
  end function say_cat
end module MFCat

program test_MFCat
  use MFCat
  implicit none
  type(TFCat) :: cat

  print *, cat%say()
end program test_MFCat