module FoX_wcml
  implicit none
  private

  public :: cmlBeginFile, cmlFinishFile, cmlAddNamespace, cmlStartCml, cmlEndCml

contains

  subroutine cmlBeginFile()
    print *, "Beginning file..."
  end subroutine cmlBeginFile

  subroutine cmlFinishFile()
    print *, "Finishing file..."
  end subroutine cmlFinishFile

  subroutine cmlAddNamespace()
    print *, "Adding namespace..."
  end subroutine cmlAddNamespace

  subroutine cmlStartCml()
    print *, "Starting CML..."
  end subroutine cmlStartCml

  subroutine cmlEndCml()
    print *, "Ending CML..."
  end subroutine cmlEndCml

end module FoX_wcml

program testFoX_wcml
  use FoX_wcml
  implicit none

  call cmlBeginFile()
  call cmlAddNamespace()
  call cmlStartCml()
  call cmlEndCml()
  call cmlFinishFile()

  print *, "Test completed successfully."
end program testFoX_wcml