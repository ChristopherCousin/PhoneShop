--
-- PostgreSQL database dump
--

-- Dumped from database version 10.6
-- Dumped by pg_dump version 10.6

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: availablephones; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.availablephones (
    nombreavailablephones character varying
);


ALTER TABLE public.availablephones OWNER TO usuario;

--
-- Name: availablerepairs; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.availablerepairs (
    phonenameavailablerepairs character varying,
    repairnameavailablerepairs character varying,
    priceavailablerepairs integer
);


ALTER TABLE public.availablerepairs OWNER TO usuario;

--
-- Name: orders; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.orders (
    statusorders character varying,
    phoneorders character varying,
    repairorders character varying,
    orderidorders uuid,
    dateorders timestamp with time zone
);


ALTER TABLE public.orders OWNER TO usuario;

--
-- Name: users; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.users (
    iduser character varying NOT NULL,
    passworduser character varying NOT NULL,
    privilegesuser character varying
);


ALTER TABLE public.users OWNER TO usuario;

--
-- Data for Name: availablephones; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.availablephones (nombreavailablephones) FROM stdin;
Iphone
\.


--
-- Data for Name: availablerepairs; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.availablerepairs (phonenameavailablerepairs, repairnameavailablerepairs, priceavailablerepairs) FROM stdin;
asd	asd	12
Android	100	100
Android	Pantalla	200
Android	Audio	200
IPhone	Pantalla	300
Iphone	Pantalla	200
Iphone	Pantalla	200
\.


--
-- Data for Name: orders; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.orders (statusorders, phoneorders, repairorders, orderidorders, dateorders) FROM stdin;
done	Iphone	Pantalla	78c626fb-59d8-45fd-91ff-6ea40521bf1d	2019-01-30 20:45:32.740508+01
done	Iphone 6	asd	531e59b7-eda6-4f0d-a930-3015866f1265	2019-01-30 20:59:02.799716+01
done	Android	100	f699cf29-bb15-4d88-afd1-3ca7a0ec97a6	2019-01-31 12:38:18.889955+01
done	Iphone	Pantalla	1cccdb1d-1d29-435a-8e4a-4061230488b2	2019-01-31 13:57:51.863999+01
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.users (iduser, passworduser, privilegesuser) FROM stdin;
admin	admin	3
\.


--
-- Name: users users_iduser_key; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_iduser_key UNIQUE (iduser);


--
-- PostgreSQL database dump complete
--

