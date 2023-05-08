#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void c_elf(unsigned char *a);
void p_magic(unsigned char *a);
void p_class(unsigned char *a);
void p_data(unsigned char *a);
void p_version(unsigned char *a);
void p_abi(unsigned char *a);
void p_osabi(unsigned char *a);
void p_type(unsigned int x, unsigned char *a);
void p_entry(unsigned long int z, unsigned char *a);
void cl_elf(int e);


/**
 * c_elf - Checks if a file is an ELF file.
 * @a: A pointer to an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file - exit code 98.
 */
void c_elf(unsigned char *a)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (a[i] != 127 &&
			a[i] != 'E' &&
			a[i] != 'L' &&
			a[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * p_magic - Prints the magic numbers of an ELF header.
 * @a: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void p_magic(unsigned char *a)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", a[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * p_class - Prints the class of an ELF header.
 * @a: A pointer to an array containing the ELF class.
 */
void p_class(unsigned char *a)
{
	printf("  Class:                             ");

	switch (a[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", a[EI_CLASS]);
	}
}

/**
 * p_data - Prints the data of an ELF header.
 * @a: A pointer to an array containing the ELF class.
 */
void p_data(unsigned char *a)
{
	printf("  Data:                              ");

	switch (a[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", a[EI_CLASS]);
	}
}

/**
 * p_version - Prints the version of an ELF header.
 * @a: A pointer to an array containing the ELF version.
 */
void p_version(unsigned char *a)
{
	printf("  Version:                           %d",
		   a[EI_VERSION]);

	switch (a[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * p_osabi - Prints the OS/ABI of an ELF header.
 * @a: A pointer to an array containing the ELF version.
 */
void p_osabi(unsigned char *a)
{
	printf("  OS/ABI:                            ");

	switch (a[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", a[EI_OSABI]);
	}
}

/**
 * p_abi - Prints the ABI version of an ELF header.
 * @a: A pointer to an array containing the ELF ABI version.
 */
void p_abi(unsigned char *a)
{
	printf("  ABI Version:                       %d\n",
		   a[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @x: The ELF type.
 * @a: A pointer to an array containing the ELF class.
 */
void p_type(unsigned int x, unsigned char *a)
{
	if (a[EI_DATA] == ELFDATA2MSB)
		x >>= 8;

	printf("  Type:                              ");

	switch (x)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", x);
	}
}

/**
 * p_entry - Prints the entry point of an ELF header.
 * @z: The address of the ELF entry point.
 * @a: A pointer to an array containing the ELF class.
 */
void p_entry(unsigned long int z, unsigned char *a)
{
	printf("  Entry point address:               ");

	if (a[EI_DATA] == ELFDATA2MSB)
	{
		z = ((z << 8) & 0xFF00FF00) |
				  ((z >> 8) & 0xFF00FF);
		z = (z << 16) | (z >> 16);
	}

	if (a[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)z);

	else
		printf("%#lx\n", z);
}

/**
 * cl_elf - Closes an ELF file.
 * @e: The file descriptor of the ELF file.
 * Description: If the file cannot be closed - exit code 98.
 */
void cl_elf(int e)
{
	if (close(e) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", e);

		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @ac: The number of arguments supplied to the program.
 * @av: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) ac, char *av[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(av[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		cl_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		cl_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}

	c_elf(header->a);
	printf("ELF Header:\n");
	p_magic(header->a);
	p_class(header->a);
	p_data(header->a);
	p_version(header->a);
	p_osabi(header->a);
	p_abi(header->a);
	p_type(header->x, header->a);
	p_entry(header->z, header->a);

	free(header);
	cl_elf(o);
	return (0);
}
