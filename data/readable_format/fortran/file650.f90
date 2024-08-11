MODULE CppWrappers
  USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_PTR, C_FUNPTR, C_F_PROCPOINTER, C_LOC, C_F_POINTER

  IMPLICIT NONE

  TYPE, BIND(C) :: Container
    INTEGER :: data = 0
  END TYPE Container

  CONTAINS

    SUBROUTINE convert_c_funcpointer(c_func_pointer, fpointer)
      TYPE(C_FUNPTR), VALUE :: c_func_pointer
      PROCEDURE(), POINTER :: fpointer
      CALL C_F_PROCPOINTER(c_func_pointer, fpointer)
    END SUBROUTINE convert_c_funcpointer

    SUBROUTINE allocate_Container(Container_cptr)
      TYPE(C_PTR) :: Container_cptr
      TYPE(Container), POINTER :: Container_fptr
      ALLOCATE(Container_fptr)
      Container_cptr = C_LOC(Container_fptr)
    END SUBROUTINE allocate_Container

    SUBROUTINE deallocate_Container(Container_cptr)
      TYPE(C_PTR) :: Container_cptr
      TYPE(Container), POINTER :: Container_fptr
      CALL C_F_POINTER(Container_cptr, Container_fptr)
      DEALLOCATE(Container_fptr)
    END SUBROUTINE deallocate_Container

END MODULE CppWrappers

MODULE TestFunctions
  USE ISO_C_BINDING
  IMPLICIT NONE

  CONTAINS

    SUBROUTINE testFunc() BIND(C)
      PRINT *, "Function pointer conversion successful."
    END SUBROUTINE testFunc

END MODULE TestFunctions

PROGRAM TestCppWrappers
  USE CppWrappers
  USE TestFunctions
  IMPLICIT NONE

  TYPE(C_FUNPTR) :: c_func_pointer
  PROCEDURE(), POINTER :: fpointer => NULL()
  TYPE(C_PTR) :: Container_cptr
  TYPE(Container), POINTER :: Container_ptr

  ! Test convert_c_funcpointer
  c_func_pointer = C_FUNLOC(testFunc)
  CALL convert_c_funcpointer(c_func_pointer, fpointer)
  CALL fpointer

  ! Test allocate_Container and deallocate_Container
  CALL allocate_Container(Container_cptr)
  CALL C_F_POINTER(Container_cptr, Container_ptr)
  ! Here you could manipulate Container_ptr if needed
  CALL deallocate_Container(Container_cptr)

END PROGRAM TestCppWrappers