PROGRAM TestCTRMMF
  CHARACTER*1        SIDE, UPLO, TRANSA, DIAG
  INTEGER            M, N, LDA, LDB
  COMPLEX            ALPHA
  COMPLEX            A(2, 2), B(2, 2)
  
  SIDE = 'L'
  UPLO = 'U'
  TRANSA = 'N'
  DIAG = 'N'
  M = 2
  N = 2
  LDA = 2
  LDB = 2
  ALPHA = (1.0, 0.0)
  
  A(1, 1) = (1.0, 0.0)
  A(1, 2) = (0.0, 0.0)
  A(2, 1) = (0.0, 0.0)
  A(2, 2) = (1.0, 0.0)
  
  B(1, 1) = (1.0, 1.0)
  B(1, 2) = (2.0, 2.0)
  B(2, 1) = (3.0, 3.0)
  B(2, 2) = (4.0, 4.0)
  
  CALL CTRMMF(SIDE, UPLO, TRANSA, DIAG, M, N, ALPHA, A, LDA, B, LDB)
  
  PRINT *, 'B after calling CTRMMF:'
  PRINT *, B(1, 1), B(1, 2)
  PRINT *, B(2, 1), B(2, 2)
  
END PROGRAM TestCTRMMF

SUBROUTINE CTRMMF ( SIDE, UPLO, TRANSA, DIAG, M, N, ALPHA, A, LDA, B, LDB )
  CHARACTER*1        SIDE, UPLO, TRANSA, DIAG
  INTEGER            M, N, LDA, LDB
  COMPLEX            ALPHA
  COMPLEX            A( LDA, * ), B( LDB, * )
  RETURN
END