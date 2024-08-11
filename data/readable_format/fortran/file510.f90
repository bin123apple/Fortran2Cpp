! Save this code as ctme.f90
Subroutine Ctme (T, Ih, Im, Is)
  Implicit None
  Integer, Intent(In) :: T
  Integer, Intent(Out) :: Ih, Im
  Real, Intent(Out) :: Is
  
  Ih = T / 3600
  Im = (T / 60) - (Ih * 60)
  Is = Real(T - Ih * 3600 - Im * 60)
End Subroutine Ctme

Program TestCtme
  Implicit None
  Integer :: Ih, Im, T
  Real :: Is
  
  ! Test case 1
  T = 3661
  Call Ctme(T, Ih, Im, Is)
  Write(*,*) 'Test 1:', Ih, Im, Is
  
  ! Additional test cases...
  T = 86399
  Call Ctme(T, Ih, Im, Is)
  Write(*,*) 'Test 2:', Ih, Im, Is
  
  T = 0
  Call Ctme(T, Ih, Im, Is)
  Write(*,*) 'Test 3:', Ih, Im, Is
  
  T = 60
  Call Ctme(T, Ih, Im, Is)
  Write(*,*) 'Test 4:', Ih, Im, Is
  
  T = 3600
  Call Ctme(T, Ih, Im, Is)
  Write(*,*) 'Test 5:', Ih, Im, Is
  
End Program TestCtme