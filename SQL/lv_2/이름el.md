# 프로그래머스 lv.2 이름에 el 이 들어가는 동물 찾기

## solution 1

### mysql

```mysql
-- 코드를 입력하세요
SELECT ANIMAL_ID , name from ANIMAL_INS  where name like '%el%' and animal_type = 'dog' order by name;
```



## solution 2


### oracle

```oracle
-- 코드를 입력하세요
SELECT ANIMAL_ID , name from ANIMAL_INS 
where lower(name) like '%el%' and animal_type like 'Dog' order by name;
```