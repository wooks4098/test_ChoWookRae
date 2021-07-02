USE master
GO
--CorpDB �����ͺ��̽��� ����.
CREATE DATABASE CorpDB
GO
USE CorpDB
GO
--DEPARTMENT Table ����.
CREATE TABLE DEPARTMENT(
DNO		int PRIMARY KEY,	-- �μ���ȣ / �⺻Ű ����.
DNAME	nvarchar(20),		-- �μ���.
LOC		nchar(20)			-- ������.
)
GO
--DEPARTMENT Table�� ������ �߰�.
INSERT INTO department(dno, dname, loc) VALUES(10, '�渮��', '����')
INSERT INTO department(dname, loc, dno) VALUES('�λ��', '��õ', 20)
INSERT INTO department(loc, dno, dname) VALUES('����', 30, '������')
INSERT INTO department VALUES(40, '�����', '��õ')
GO
--EMPLOYEE Table ����.
CREATE TABLE EMPLOYEE(
ENO			int PRIMARY KEY,	-- �����ȣ / �⺻Ű ����.
ENAME		nvarchar(20),		-- �����.
JOB			nvarchar(20),		-- ������.
MANAGER		int,				-- ����� �����ȣ.
HIREDATE	datetime,			-- �Ի���.
SALARY		int,				-- �޿�.
COMMISION	int,
DNO			int					-- �μ���ȣ.
)
GO
--EMPLOYEE Table�� ������ �߰�.
INSERT INTO employee VALUES(1001, '����', '���', 1013, '2007-03-01', 300, NULL, 20)
INSERT INTO employee VALUES(1002, '�ѿ���', '�븮', 1005, '2007-04-02', 250, 80, 30)
INSERT INTO employee VALUES(1003, '����ȣ', '����', 1008, '2005-02-10', 500, 100, 30)
INSERT INTO employee VALUES(1004, '�̺���', '����', 1005, '2003-09-02', 600, NULL, 20)
INSERT INTO employee VALUES(1005, '�ŵ���', '����', 1005, '2005-04-07', 450, 200, 30)
INSERT INTO employee VALUES(1006, '�嵿��', '����', 1008, '2003-10-09', 480, NULL, 30)
INSERT INTO employee VALUES(1007, '�̹���', '����', 1008, '2004-01-08', 520, NULL, 10)
INSERT INTO employee VALUES(1008, '������', '����', 1003, '2004-03-08', 500, 0, 30)
INSERT INTO employee VALUES(1009, '�ȼ���', '����', NULL, '1996-10-04', 1000, NULL, 20)
INSERT INTO employee VALUES(1010, '�̺���', '����', 1003, '2005-04-07', 500, NULL, 10)
INSERT INTO employee VALUES(1011, '������', '���', 1006, '2007-08-09', 300, NULL, 20)
INSERT INTO employee VALUES(1012, '������', '����', 1003, '2002-10-09', 560, NULL, 20)
INSERT INTO employee VALUES(1013, '���μ�', '���', 1006, '2007-11-09', 250, NULL, 10)
GO
--SALGRADE Table ����.
CREATE TABLE SALGRADE(
GRADE	int PRIMARY KEY,	-- �޿����.
LOWSAL	int,				-- �޿� ���Ѱ�.
HIGHSAL	int					-- �޿� ���Ѱ�.
)
GO
--SALGRADE Table�� ������ �߰�.
INSERT INTO salgrade VALUES(1, 901, 1000)
INSERT INTO salgrade VALUES(2, 501, 901)
INSERT INTO salgrade VALUES(3, 401, 500)
INSERT INTO salgrade VALUES(4, 301, 400)
INSERT INTO salgrade VALUES(5, 201, 300)