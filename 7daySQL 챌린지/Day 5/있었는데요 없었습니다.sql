-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS
WHERE DATETIME >
    (SELECT DATETIME FROM ANIMAL_OUTS
     WHERE ANIMAL_ID = ANIMAL_INS.ANIMAL_ID)
ORDER BY DATETIME