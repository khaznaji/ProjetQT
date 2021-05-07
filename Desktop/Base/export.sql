--------------------------------------------------------
--  Fichier créé - jeudi-mai-06-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ACTIVITE
--------------------------------------------------------

  CREATE TABLE "LINA"."ACTIVITE" 
   (	"NOM" VARCHAR2(255 BYTE), 
	"TYPE" VARCHAR2(255 BYTE), 
	"DUREE" NUMBER, 
	"NBR" NUMBER, 
	"DATEACT" VARCHAR2(255 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ADHERANT
--------------------------------------------------------

  CREATE TABLE "LINA"."ADHERANT" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(255 BYTE), 
	"PRENOM" VARCHAR2(255 BYTE), 
	"NUMTEL" NUMBER, 
	"MAIL" VARCHAR2(255 BYTE), 
	"TYPE" VARCHAR2(255 BYTE), 
	"COMPETENCE" VARCHAR2(255 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ARDUINO
--------------------------------------------------------

  CREATE TABLE "LINA"."ARDUINO" 
   (	"ID" VARCHAR2(20 BYTE), 
	"PRESENCE" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ARTICLE
--------------------------------------------------------

  CREATE TABLE "LINA"."ARTICLE" 
   (	"ID" NUMBER, 
	"MSG" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"TITRE" VARCHAR2(20 BYTE), 
	"DT" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EVENEMENT
--------------------------------------------------------

  CREATE TABLE "LINA"."EVENEMENT" 
   (	"TITRE" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"LIEU" VARCHAR2(20 BYTE), 
	"DATEDEBUT" VARCHAR2(20 BYTE), 
	"DATEFIN" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FONCTION
--------------------------------------------------------

  CREATE TABLE "LINA"."FONCTION" 
   (	"ID" NUMBER, 
	"DEP" VARCHAR2(20 BYTE), 
	"DIR" VARCHAR2(20 BYTE), 
	"SER" VARCHAR2(20 BYTE), 
	"POS" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FOURNISSEURS
--------------------------------------------------------

  CREATE TABLE "LINA"."FOURNISSEURS" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(20 BYTE), 
	"NUM" NUMBER, 
	"NIVEAU" VARCHAR2(20 BYTE), 
	"CONTROLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table HISTORIQUE
--------------------------------------------------------

  CREATE TABLE "LINA"."HISTORIQUE" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"DATEE" VARCHAR2(20 BYTE), 
	"FN" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table HISTORIQUE2
--------------------------------------------------------

  CREATE TABLE "LINA"."HISTORIQUE2" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"DATEE" VARCHAR2(20 BYTE), 
	"FN" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOGIN
--------------------------------------------------------

  CREATE TABLE "LINA"."LOGIN" 
   (	"ID_LOGIN" NUMBER, 
	"MDP_LOGIN" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MARKETING
--------------------------------------------------------

  CREATE TABLE "LINA"."MARKETING" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(255 BYTE), 
	"TYPE" VARCHAR2(255 BYTE), 
	"DATEM" VARCHAR2(255 BYTE), 
	"NUME" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MATERIEL
--------------------------------------------------------

  CREATE TABLE "LINA"."MATERIEL" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"COUT" NUMBER, 
	"DUREE" NUMBER, 
	"VOLUME" NUMBER, 
	"POIDS" NUMBER, 
	"NBR" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MEMBRE
--------------------------------------------------------

  CREATE TABLE "LINA"."MEMBRE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ADR" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(20 BYTE), 
	"NUM" NUMBER, 
	"SLR" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PARTENAIRE
--------------------------------------------------------

  CREATE TABLE "LINA"."PARTENAIRE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(255 BYTE), 
	"PRENOM" VARCHAR2(255 BYTE), 
	"ADRESSEM" VARCHAR2(255 BYTE), 
	"NUM" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PARTICIPANT
--------------------------------------------------------

  CREATE TABLE "LINA"."PARTICIPANT" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(20 BYTE), 
	"CIN" NUMBER, 
	"NUMTEL" NUMBER, 
	"DATENAISSANCE" VARCHAR2(20 BYTE), 
	"TYPEEVE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PROJET
--------------------------------------------------------

  CREATE TABLE "LINA"."PROJET" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(255 BYTE), 
	"TYPE" VARCHAR2(30 BYTE), 
	"STATUS" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"DATEDEBUT" VARCHAR2(255 BYTE), 
	"BUDGET" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PUBLICITE
--------------------------------------------------------

  CREATE TABLE "LINA"."PUBLICITE" 
   (	"ID" NUMBER, 
	"TITRE" VARCHAR2(20 BYTE), 
	"FORM" VARCHAR2(20 BYTE), 
	"DESCRIPTION" VARCHAR2(20 BYTE), 
	"DTE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table SPONSOR
--------------------------------------------------------

  CREATE TABLE "LINA"."SPONSOR" 
   (	"ID" NUMBER, 
	"ADRESSE" VARCHAR2(255 BYTE), 
	"MAIL" VARCHAR2(255 BYTE), 
	"NUMTEL" NUMBER, 
	"NOM" VARCHAR2(255 BYTE), 
	"PRODUIT" VARCHAR2(255 BYTE), 
	"CONVENTION" VARCHAR2(255 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into LINA.ACTIVITE
SET DEFINE OFF;
Insert into LINA.ACTIVITE (NOM,TYPE,DUREE,NBR,DATEACT) values ('cc','zs',null,null,'01-JAN-00');
Insert into LINA.ACTIVITE (NOM,TYPE,DUREE,NBR,DATEACT) values ('rrrr',null,null,null,'01-JAN-00');
Insert into LINA.ACTIVITE (NOM,TYPE,DUREE,NBR,DATEACT) values ('yyt','zs',null,null,'01-JAN-00');
Insert into LINA.ACTIVITE (NOM,TYPE,DUREE,NBR,DATEACT) values ('rz','e',null,null,'01-JAN-00');
Insert into LINA.ACTIVITE (NOM,TYPE,DUREE,NBR,DATEACT) values ('rrrz',null,null,null,'01-JAN-00');
Insert into LINA.ACTIVITE (NOM,TYPE,DUREE,NBR,DATEACT) values ('n',null,null,null,'01-JAN-00');
REM INSERTING into LINA.ADHERANT
SET DEFINE OFF;
Insert into LINA.ADHERANT (ID,NOM,PRENOM,NUMTEL,MAIL,TYPE,COMPETENCE) values ('12','z',null,null,null,null,null);
Insert into LINA.ADHERANT (ID,NOM,PRENOM,NUMTEL,MAIL,TYPE,COMPETENCE) values ('1787','z',null,null,null,null,null);
Insert into LINA.ADHERANT (ID,NOM,PRENOM,NUMTEL,MAIL,TYPE,COMPETENCE) values ('87','tttttt','tttttt','352','t','t','tr');
Insert into LINA.ADHERANT (ID,NOM,PRENOM,NUMTEL,MAIL,TYPE,COMPETENCE) values ('87','tttttt','tttttt','352','t','t','tr');
Insert into LINA.ADHERANT (ID,NOM,PRENOM,NUMTEL,MAIL,TYPE,COMPETENCE) values ('87','tttttt','tttttt','352','t','t','tr');
Insert into LINA.ADHERANT (ID,NOM,PRENOM,NUMTEL,MAIL,TYPE,COMPETENCE) values ('99','tttttt','tttttt','352','t','t','tr');
REM INSERTING into LINA.ARDUINO
SET DEFINE OFF;
Insert into LINA.ARDUINO (ID,PRESENCE,PRENOM,NOM) values ('7A 69 89 3B','0','x','y');
Insert into LINA.ARDUINO (ID,PRESENCE,PRENOM,NOM) values ('69 42 49 B3','0','a','b');
REM INSERTING into LINA.ARTICLE
SET DEFINE OFF;
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('12',null,'w','w','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('21','d','d','d','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('211',null,'w','w','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('121','z','a','b','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('121','z','a','b','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('121','z','a','b','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('121','z','a','b','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('21','d','d','d','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('87','e','z','a','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('54','r','t','y','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('21','d','d','d','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('0','w','w','w','2000/01/01');
Insert into LINA.ARTICLE (ID,MSG,TYPE,TITRE,DT) values ('421','d','d','a','2000/01/01');
REM INSERTING into LINA.EVENEMENT
SET DEFINE OFF;
Insert into LINA.EVENEMENT (TITRE,TYPE,LIEU,DATEDEBUT,DATEFIN) values ('aaa','aqs','a','a','a');
Insert into LINA.EVENEMENT (TITRE,TYPE,LIEU,DATEDEBUT,DATEFIN) values ('ggg','edede','a','12','32');
Insert into LINA.EVENEMENT (TITRE,TYPE,LIEU,DATEDEBUT,DATEFIN) values ('rg','edede','a','12','32');
Insert into LINA.EVENEMENT (TITRE,TYPE,LIEU,DATEDEBUT,DATEFIN) values ('a','aqs','a','a','a');
REM INSERTING into LINA.FONCTION
SET DEFINE OFF;
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('12','dep','dir','dir','dd');
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('121',null,null,'ll',null);
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('2121','vcv','aaa','aze','rt');
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('78',null,null,'ooo',null);
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('788',null,null,'oo','jj');
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('8','za','za','za','az');
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('54','ee','rrrr','eee','ttttttt');
Insert into LINA.FONCTION (ID,DEP,DIR,SER,POS) values ('12','dep','dir','dir','dir');
REM INSERTING into LINA.FOURNISSEURS
SET DEFINE OFF;
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('1','dd','dd','w@fm.c','21','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('78','cccc','s','w@fm.c','521','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('5454','cccc','w','w@fm.c','21','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('60','cccc','s','w@fm.c','521','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('5','s','s','ss@s.s','5','s','s');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('88','s','s','s@s.dc','5','c','c');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('21','v','v','v@v.v','212','v','vvvvvvvvvv');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('122','v','v','v@v.v','51','vv','vv');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('121','efjjns','w','w@fm.c','21','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('151','ds','w','w@fm.c','21','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('98','dd','aaa','w@fm.c','21','w','w');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('7','v','v','v@v.v','212','v','vvvvvvvvvv');
Insert into LINA.FOURNISSEURS (ID,NOM,PRENOM,MAIL,NUM,NIVEAU,CONTROLE) values ('4','v','v','v@v.v','212','v','vvvvvvvvvv');
REM INSERTING into LINA.HISTORIQUE
SET DEFINE OFF;
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'28 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'04 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE (NOM,DATEE,FN) values (null,'06 / 05 / 2021 ','ajouter');
REM INSERTING into LINA.HISTORIQUE2
SET DEFINE OFF;
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','supprimer');
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','supprimer');
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','ajouter');
Insert into LINA.HISTORIQUE2 (NOM,DATEE,FN) values ('www','29 / 04 / 2021 ','ajouter');
REM INSERTING into LINA.LOGIN
SET DEFINE OFF;
REM INSERTING into LINA.MARKETING
SET DEFINE OFF;
Insert into LINA.MARKETING (ID,NOM,TYPE,DATEM,NUME) values ('1','www','aa','wwww','11');
Insert into LINA.MARKETING (ID,NOM,TYPE,DATEM,NUME) values ('21','www','aa','wwww','11');
Insert into LINA.MARKETING (ID,NOM,TYPE,DATEM,NUME) values ('231','www','aa','wwww','11');
REM INSERTING into LINA.MATERIEL
SET DEFINE OFF;
Insert into LINA.MATERIEL (NOM,TYPE,COUT,DUREE,VOLUME,POIDS,NBR) values ('dd','d','0','0','0','0','0');
Insert into LINA.MATERIEL (NOM,TYPE,COUT,DUREE,VOLUME,POIDS,NBR) values ('dd','d','0','0','0','0','0');
Insert into LINA.MATERIEL (NOM,TYPE,COUT,DUREE,VOLUME,POIDS,NBR) values ('dd','d','0','545','0','0','0');
Insert into LINA.MATERIEL (NOM,TYPE,COUT,DUREE,VOLUME,POIDS,NBR) values ('d','d','0','5121','61','61','61');
Insert into LINA.MATERIEL (NOM,TYPE,COUT,DUREE,VOLUME,POIDS,NBR) values ('d','dddddd','5121','61','511','511','121');
Insert into LINA.MATERIEL (NOM,TYPE,COUT,DUREE,VOLUME,POIDS,NBR) values ('c','c','32','2','35','5','5');
REM INSERTING into LINA.MEMBRE
SET DEFINE OFF;
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('89','lolol','iii','ll','gf','1000','33');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('89','lolol','iii','ll','gf','0','1000');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('200','lolol','iii','ll','gf','1000','1000');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('200','lolol','iii','ll','gf','1000','2');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('53','q','q','q','q@q.q','322','535');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('21','q','q','q','q@q.v','20','122');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('54','ccc','ccccc','cccccc','c@c.c','0','0');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('0',null,null,null,'kk@kk.n','0','0');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('0',null,null,null,'k@kl.n','0','0');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('8','a','ecc','cccc','q@q.c','500','500');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('62','xx','x','x','x@x.c','312','123');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('21','q','q','q','q@q.v','20','122');
Insert into LINA.MEMBRE (ID,NOM,PRENOM,ADR,MAIL,NUM,SLR) values ('21','q','q','q','q@qv.v','665','511');
REM INSERTING into LINA.PARTENAIRE
SET DEFINE OFF;
Insert into LINA.PARTENAIRE (ID,NOM,PRENOM,ADRESSEM,NUM) values ('13','ee','gg','w','121');
Insert into LINA.PARTENAIRE (ID,NOM,PRENOM,ADRESSEM,NUM) values ('13','ee','gg','w','121');
Insert into LINA.PARTENAIRE (ID,NOM,PRENOM,ADRESSEM,NUM) values ('10','ee','gg','w','121');
REM INSERTING into LINA.PARTICIPANT
SET DEFINE OFF;
Insert into LINA.PARTICIPANT (NOM,PRENOM,MAIL,CIN,NUMTEL,DATENAISSANCE,TYPEEVE) values ('ddddddd','s','s','521','0',null,null);
REM INSERTING into LINA.PROJET
SET DEFINE OFF;
Insert into LINA.PROJET (ID,NOM,TYPE,STATUS,ADRESSE,DATEDEBUT,BUDGET) values ('12','x','xxxx','x','xxxx','32','1213');
Insert into LINA.PROJET (ID,NOM,TYPE,STATUS,ADRESSE,DATEDEBUT,BUDGET) values ('13','x','xxxx','x','xxxx','32','1213');
REM INSERTING into LINA.PUBLICITE
SET DEFINE OFF;
Insert into LINA.PUBLICITE (ID,TITRE,FORM,DESCRIPTION,DTE) values ('7','asa','s',null,null);
Insert into LINA.PUBLICITE (ID,TITRE,FORM,DESCRIPTION,DTE) values ('5121','asa','s',null,null);
Insert into LINA.PUBLICITE (ID,TITRE,FORM,DESCRIPTION,DTE) values ('51534643','asa','s',null,null);
Insert into LINA.PUBLICITE (ID,TITRE,FORM,DESCRIPTION,DTE) values ('65','asa','s',null,null);
Insert into LINA.PUBLICITE (ID,TITRE,FORM,DESCRIPTION,DTE) values ('65','dd','s',null,null);
REM INSERTING into LINA.SPONSOR
SET DEFINE OFF;
Insert into LINA.SPONSOR (ID,ADRESSE,MAIL,NUMTEL,NOM,PRODUIT,CONVENTION) values ('65131','aa','w','5121','a','w','w');
Insert into LINA.SPONSOR (ID,ADRESSE,MAIL,NUMTEL,NOM,PRODUIT,CONVENTION) values ('99999','aa','w','5121','a','w','w');
Insert into LINA.SPONSOR (ID,ADRESSE,MAIL,NUMTEL,NOM,PRODUIT,CONVENTION) values ('53','aa','w','5121','a','w','w');
Insert into LINA.SPONSOR (ID,ADRESSE,MAIL,NUMTEL,NOM,PRODUIT,CONVENTION) values ('0','aa','w','5121','a','w','w');
Insert into LINA.SPONSOR (ID,ADRESSE,MAIL,NUMTEL,NOM,PRODUIT,CONVENTION) values ('5','w','w','54','w','w','w');
--------------------------------------------------------
--  DDL for Index ARDUINO_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LINA"."ARDUINO_PK" ON "LINA"."ARDUINO" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FOURNISSEURS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LINA"."FOURNISSEURS_PK" ON "LINA"."FOURNISSEURS" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ACTIVITE
--------------------------------------------------------

  ALTER TABLE "LINA"."ACTIVITE" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ADHERANT
--------------------------------------------------------

  ALTER TABLE "LINA"."ADHERANT" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ARDUINO
--------------------------------------------------------

  ALTER TABLE "LINA"."ARDUINO" ADD CONSTRAINT "ARDUINO_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "LINA"."ARDUINO" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ARTICLE
--------------------------------------------------------

  ALTER TABLE "LINA"."ARTICLE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EVENEMENT
--------------------------------------------------------

  ALTER TABLE "LINA"."EVENEMENT" MODIFY ("TITRE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FONCTION
--------------------------------------------------------

  ALTER TABLE "LINA"."FONCTION" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FOURNISSEURS
--------------------------------------------------------

  ALTER TABLE "LINA"."FOURNISSEURS" ADD CONSTRAINT "FOURNISSEURS_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "LINA"."FOURNISSEURS" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table HISTORIQUE2
--------------------------------------------------------

  ALTER TABLE "LINA"."HISTORIQUE2" MODIFY ("FN" NOT NULL ENABLE);
  ALTER TABLE "LINA"."HISTORIQUE2" MODIFY ("DATEE" NOT NULL ENABLE);
  ALTER TABLE "LINA"."HISTORIQUE2" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MARKETING
--------------------------------------------------------

  ALTER TABLE "LINA"."MARKETING" MODIFY ("NUME" NOT NULL ENABLE);
  ALTER TABLE "LINA"."MARKETING" MODIFY ("DATEM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."MARKETING" MODIFY ("TYPE" NOT NULL ENABLE);
  ALTER TABLE "LINA"."MARKETING" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."MARKETING" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MATERIEL
--------------------------------------------------------

  ALTER TABLE "LINA"."MATERIEL" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MEMBRE
--------------------------------------------------------

  ALTER TABLE "LINA"."MEMBRE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PARTENAIRE
--------------------------------------------------------

  ALTER TABLE "LINA"."PARTENAIRE" MODIFY ("NUM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PARTENAIRE" MODIFY ("ADRESSEM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PARTENAIRE" MODIFY ("PRENOM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PARTENAIRE" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PARTENAIRE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PARTICIPANT
--------------------------------------------------------

  ALTER TABLE "LINA"."PARTICIPANT" MODIFY ("CIN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PROJET
--------------------------------------------------------

  ALTER TABLE "LINA"."PROJET" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PROJET" MODIFY ("BUDGET" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PROJET" MODIFY ("DATEDEBUT" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PROJET" MODIFY ("STATUS" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PROJET" MODIFY ("TYPE" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PROJET" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."PROJET" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PUBLICITE
--------------------------------------------------------

  ALTER TABLE "LINA"."PUBLICITE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table SPONSOR
--------------------------------------------------------

  ALTER TABLE "LINA"."SPONSOR" MODIFY ("CONVENTION" NOT NULL ENABLE);
  ALTER TABLE "LINA"."SPONSOR" MODIFY ("PRODUIT" NOT NULL ENABLE);
  ALTER TABLE "LINA"."SPONSOR" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "LINA"."SPONSOR" MODIFY ("NUMTEL" NOT NULL ENABLE);
  ALTER TABLE "LINA"."SPONSOR" MODIFY ("MAIL" NOT NULL ENABLE);
  ALTER TABLE "LINA"."SPONSOR" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "LINA"."SPONSOR" MODIFY ("ID" NOT NULL ENABLE);
