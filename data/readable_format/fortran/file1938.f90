! combined_switches_test.f90
Module switches_bin
  Implicit None

  logical :: l_coll_coal = .True.
  logical :: l_break = .False.
  logical :: l_sed_ult = .False.
  logical :: l_two_mom = .True.
End Module switches_bin

Program test_switches_bin
  Use switches_bin
  Implicit None
  
  ! Test l_coll_coal
  If (.Not. l_coll_coal) Then
    Print *, 'Test failed: l_coll_coal is not True.'
  Else
    Print *, 'Test passed: l_coll_coal is True.'
  End If
  
  ! Test l_break
  If (l_break) Then
    Print *, 'Test failed: l_break is not False.'
  Else
    Print *, 'Test passed: l_break is False.'
  End If
  
  ! Test l_sed_ult
  If (l_sed_ult) Then
    Print *, 'Test failed: l_sed_ult is not False.'
  Else
    Print *, 'Test passed: l_sed_ult is False.'
  End If
  
  ! Test l_two_mom
  If (.Not. l_two_mom) Then
    Print *, 'Test failed: l_two_mom is not True.'
  Else
    Print *, 'Test passed: l_two_mom is True.'
  End If
End Program test_switches_bin