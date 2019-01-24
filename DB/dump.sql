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
    status_orders character varying,
    phone_orders character varying,
    repair_orders character varying,
    orderid_orders uuid
);


ALTER TABLE public.orders OWNER TO usuario;

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

COPY public.orders (status_orders, phone_orders, repair_orders, orderid_orders) FROM stdin;
\.


--
-- PostgreSQL database dump complete
--

