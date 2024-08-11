MODULE TEST
  IMPLICIT NONE
  PRIVATE
  PUBLIC :: all_type, any_type
  
  TYPE :: info_type
     INTEGER :: value
  END TYPE info_type
  
  TYPE, PUBLIC :: all_type
     TYPE(info_type) :: info
  END TYPE all_type
  
  TYPE, PUBLIC :: any_type
     TYPE(info_type) :: info
  END TYPE any_type
  
END MODULE TEST

PROGRAM test_program
  USE TEST
  IMPLICIT NONE
  
  TYPE(all_type) :: example_all
  TYPE(any_type) :: example_any
  
  ! Test for all_type
  example_all%info%value = 5
  PRINT *, 'all_type value:', example_all%info%value
  
  ! Assuming you want to manipulate and access any_type's info.
  ! Since Fortran does not allow access to private members directly and there are no setter/getter methods defined for any_type,
  ! we can't manipulate or display any_type's info value in this example without modifying the module to provide such access.
  
END PROGRAM test_program