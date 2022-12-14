USE [sistemabebidas]
GO
/****** Object:  Table [dbo].[productos]    Script Date: 29/08/2022 12:48:26 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[productos](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[marca] [varchar](100) NOT NULL,
	[nombre] [varchar](100) NOT NULL,
	[tipo] [varchar](100) NOT NULL,
	[capacidad] [float] NOT NULL,
	[precio] [float] NOT NULL,
	[stock] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[productos_obs]    Script Date: 29/08/2022 12:48:26 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[productos_obs](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[marca] [varchar](50) NOT NULL,
	[nombre] [varchar](50) NOT NULL,
	[tipo] [varchar](50) NOT NULL,
	[capacidad] [int] NOT NULL,
	[precio] [float] NOT NULL,
	[stock] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[usuarios]    Script Date: 29/08/2022 12:48:26 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[usuarios](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[nombres] [varchar](50) NOT NULL,
	[apellidos] [varchar](50) NOT NULL,
	[email] [varchar](50) NOT NULL,
	[usuario] [varchar](50) NOT NULL,
	[password] [varchar](50) NOT NULL,
	[permiso] [varchar](50) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[vigilancia]    Script Date: 29/08/2022 12:48:26 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[vigilancia](
	[ID] [int] NOT NULL,
	[NOMBRE] [varchar](100) NOT NULL,
	[APELLIDOS] [varchar](100) NOT NULL,
	[PERMISO] [varchar](100) NOT NULL,
	[HORA] [varchar](100) NOT NULL,
	[FECHA] [varchar](100) NOT NULL
) ON [PRIMARY]
GO

INSERT INTO usuarios (nombres, apellidos, email, usuario, password, permiso) VALUES
('admin1nombres', 'admin1apellidos', 'admin1@gmail.com', 'admin1', 'nqzv{>', 'Jefe de Almacen'),
('admin2nombres', 'admin2apellidos', 'admin2@gmail.com', 'admin2', 'nqzv{?', 'Controlador de Expedicion'),
('admin3nombres', 'admin3apellidos', 'admin3@gmail.com', 'admin3', 'nqzv{@', 'Controlador de Expedicion'),
('admin4nombres', 'admin4apellidos', 'admin4@gmail.com', 'admin4', 'nqzv{A', 'Operario de Pedidos'),
('admin5nombres', 'admin5apellidos', 'admin5@gmail.com', 'admin5', 'nqzv{B', 'Personal de Vigilancia');
