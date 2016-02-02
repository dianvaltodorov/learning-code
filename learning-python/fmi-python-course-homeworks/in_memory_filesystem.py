import re

__author__ = 'Dido'
ROOT = '/'


class FileSystem:

    def __init__(self, size):
        if size >= 1:
            self.file_system_nodes = {'/': Directory()}
            self.size = size
            self.available_size = size - 1
        else:
            raise NotEnoughSpaceError

    def get_node(self, path):
        if path in self.file_system_nodes:
            return self.file_system_nodes[path]
        else:
            raise NodeDoesNotExistError

    def create(self, path, directory=False, content=''):
        if path in self.file_system_nodes:
            raise DestinationNodeExistsError
        else:
            parent_path = self.get_parent_path(path)
            if parent_path not in self.file_system_nodes:
                raise DestinationNodeDoesNotExistError
            else:

                if directory:
                    size_of_new_node = 1
                else:
                    size_of_new_node = len(content) + 1

                if self.available_size - size_of_new_node < 0:
                    raise NotEnoughSpaceError
                else:
                    self.available_size -= size_of_new_node

                # Create dir
                if directory:
                    self.file_system_nodes[path] = Directory()
                    self.file_system_nodes[parent_path].directories.append(
                        self.file_system_nodes[path])
                    self.file_system_nodes[parent_path].nodes.append(
                        self.file_system_nodes[path])
                else:
                    self.file_system_nodes[path] = File(self, content=content)
                    self.file_system_nodes[parent_path].files.append(
                        self.file_system_nodes[path])
                    self.file_system_nodes[parent_path].nodes.append(
                        self.file_system_nodes[path])

    def remove(self, path, directory=False, force=True):
        if path not in self.file_system_nodes:
            raise NodeDoesNotExistError

        if self.get_node(path).is_directory:
            if directory:
                if len(self.get_node(path).nodes) > 0:
                    if force:
                        self.file_system_nodes[self.get_parent_path(
                            path)].nodes.remove(self.file_system_nodes[path])
                        self.file_system_nodes[self.get_parent_path(path)].directories.remove(
                            self.file_system_nodes[path])

                        p = re.compile('^' + path + ".*$")
                        nodes_for_removal = []

                        for current_node in self.file_system_nodes:
                            if p.match(current_node):
                                nodes_for_removal.append(current_node)

                        for node_to_remove in nodes_for_removal:
                            self.free_space(node_to_remove)
                            self.file_system_nodes.pop(node_to_remove)
                    else:
                        raise NonEmptyDirectoryDeletionError
                else:
                    self.file_system_nodes[self.get_parent_path(
                        path)].nodes.remove(self.file_system_nodes[path])
                    self.file_system_nodes[self.get_parent_path(
                        path)].directories.remove(self.file_system_nodes[path])
                    self.free_space(path)
                    self.file_system_nodes.pop(path)
            else:
                raise NonExplicitDirectoryDeletionError
        else:
            self.file_system_nodes[self.get_parent_path(
                path)].nodes.remove(self.file_system_nodes[path])
            self.file_system_nodes[self.get_parent_path(
                path)].files.remove(self.file_system_nodes[path])
            self.free_space(path)
            self.file_system_nodes.pop(path)

    def move(self, source, destination):
        if source not in self.file_system_nodes:
            raise SourceNodeDoesNotExistError

        if destination not in self.file_system_nodes:
            raise DestinationNodeDoesNotExistError
        else:
            if self.file_system_nodes[destination].is_directory:
                if self.file_system_nodes[source].is_directory:
                    nodes_to_move = []
                    p = re.compile('^' + source + '.+')
                    for current_node in self.file_system_nodes:
                        if p.match(current_node):
                            nodes_to_move.append(current_node)

                    for node_to_move in nodes_to_move:
                        if destination == '/':
                            new_node_dir = node_to_move.split(source, 1)[1]
                            new_dir = new_node_dir
                        else:
                            new_node_dir = destination + \
                                node_to_move.split(source, 1)[1]
                            new_dir = node_to_move.replace(source, destination)

                        if new_node_dir in self.file_system_nodes:
                            raise DestinationNodeExistsError
                        self.file_system_nodes[
                            new_dir] = self.file_system_nodes.pop(node_to_move)

                    self.file_system_nodes[destination].nodes.extend(
                        self.file_system_nodes[source].nodes)
                    self.file_system_nodes[destination].files.extend(
                        self.file_system_nodes[source].files)
                    self.file_system_nodes[destination].directories.extend(
                        self.file_system_nodes[source].directories)

                    self.file_system_nodes[source].nodes = []
                    self.file_system_nodes[source].files = []
                    self.file_system_nodes[source].directories = []
                else:
                    if destination == '/':
                        new_node_dir = destination + source.rsplit('/', 1)[-1]
                    else:
                        new_node_dir = destination + \
                            '/' + source.rsplit('/', 1)[-1]
                    if new_node_dir in self.file_system_nodes:
                        raise DestinationNodeExistsError
                    self.file_system_nodes[destination].nodes.append(
                        self.file_system_nodes[source])
                    self.file_system_nodes[destination].files.append(
                        self.file_system_nodes[source])
                    parent_source = self.get_parent_path(source)
                    self.file_system_nodes[parent_source].nodes.remove(
                        self.file_system_nodes[source])
                    self.file_system_nodes[parent_source].files.remove(
                        self.file_system_nodes[source])
                    self.file_system_nodes[
                        new_node_dir] = self.file_system_nodes.pop(source)
            else:
                raise DestinationNotADirectoryError

    def link(self, source, destination, symbolic=True):
        if symbolic:
            if source not in self.file_system_nodes:
                raise NodeDoesNotExistError
            else:
                self.file_system_nodes[
                    destination] = SymbolicLink(source, self)
                self.file_system_nodes[self.get_parent_path(destination)].files.append(
                    self.file_system_nodes[destination])
                self.file_system_nodes[self.get_parent_path(destination)].nodes.append(
                    self.file_system_nodes[destination])
                self.available_size -= 1
        else:
            if source not in self.file_system_nodes:
                raise SourceNodeDoesNotExistError
            else:
                if self.file_system_nodes[source].is_directory:
                    raise DirectoryHardLinkError
                else:
                    self.file_system_nodes[
                        destination] = HardLink(source, self)
                    self.file_system_nodes[self.get_parent_path(destination)].files.append(
                        self.file_system_nodes[destination])
                    self.file_system_nodes[self.get_parent_path(destination)].nodes.append(
                        self.file_system_nodes[destination])
                    self.available_size -= 1

    def mount(self, file_system, path):
        if path in self.file_system_nodes:
            if self.file_system_nodes[path].is_directory:
                if len(self.file_system_nodes[path].nodes) == 0:
                    for current_node in file_system.file_system_nodes:
                        if current_node == '/':
                            self.file_system_nodes[
                                path] = file_system.file_system_nodes[current_node]
                        else:
                            self.file_system_nodes[
                                path + current_node] = file_system.file_system_nodes[current_node]
                    self.get_node(path).is_a_file_system_mounted = True
                else:
                    raise MountPointNotEmptyError
            else:
                raise MountPointNotADirectoryError
        else:
            raise MountPointDoesNotExistError

    def unmount(self, path):
        # * Ако пътя не съществува да се хвърли NodeDoesNotExistError.
        if path in self.file_system_nodes:
            if self.get_node(path).is_a_file_system_mounted:
                p = re.compile('^' + path + ".+$")
                nodes_for_removal = []

                for current_node in self.file_system_nodes:
                    if p.match(current_node):
                        nodes_for_removal.append(current_node)

                for node_to_remove in nodes_for_removal:
                    self.file_system_nodes.pop(node_to_remove)

                self.file_system_nodes[path] = Directory()
            else:
                raise NotAMountpointError
        else:
            raise NodeDoesNotExistError

    @staticmethod
    def get_parent_path(path):
        parent_path = path.rsplit('/', 1)[0]
        if parent_path == '':
            parent_path = '/'
        return parent_path

    def free_space(self, path):
        if self.get_node(path).is_directory:
            space_to_free = 1
        else:
            space_to_free = 1 + len(self.get_node(path).content)
        self.available_size += space_to_free


class File():
    is_directory = False
    size = 1

    def __init__(self, file_system, content=''):
        self.content = content
        self.size = len(self.content) + 1
        self.file_system = file_system

    def append(self, text):
        if self.file_system.available_size - len(text) < 0:

            raise NotEnoughSpaceError
        else:
            self.content = self.content + text
            self.size += len(text)
            self.file_system.available_size -= len(text)

    def truncate(self, text):
        if self.file_system.available_size + len(self.content) - len(text) < 0:
            raise NotEnoughSpaceError
        else:
            self.content = text
            self.size = len(self.content) + 1
            self.file_system.available_size = len(self.content) + 1


class Directory():
    is_directory = True
    is_a_file_system_mounted = False

    def __init__(self):
        self.directories = list()
        self.files = list()
        self.nodes = list()


class SymbolicLink(File):

    def __init__(self, link_path, file_system):
        self.link_path = link_path
        self.file_system = file_system

    @property
    def content(self):
        if self.link_path not in self.file_system.file_system_nodes:
            raise LinkPathError
        else:
            if self.file_system.file_system_nodes[self.link_path].is_directory:
                raise LinkPathError
            else:
                return self.file_system.file_system_nodes[self.link_path].content

    @property
    def files(self):
        if self.link_path not in self.file_system.file_system_nodes:
            raise LinkPathError
        else:
            if self.file_system.file_system_nodes[self.link_path].is_directory:
                return self.file_system.file_system_nodes[self.link_path].files
            else:
                raise LinkPathError

    @property
    def directories(self):
        if self.link_path not in self.file_system.file_system_nodes:
            raise LinkPathError
        else:
            if self.file_system.file_system_nodes[self.link_path].is_directory:
                return self.file_system.file_system_nodes[self.link_path].directories
            else:
                raise LinkPathError

    @property
    def nodes(self):
        if self.link_path not in self.file_system.file_system_nodes:
            raise LinkPathError
        else:
            if self.file_system.file_system_nodes[self.link_path].is_directory:
                return self.file_system.file_system_nodes[self.link_path].nodes
            else:
                raise LinkPathError

    def append(self, text):
        self.file_system.file_system_nodes[self.link_path].append(text)

    def truncate(self, text):
        self.file_system.file_system_nodes[self.link_path].truncate(text)


class HardLink():

    def __init__(self, link_path, file_system):
        self.file_system = file_system
        self.link_path = link_path
        self.file_system = file_system

    @property
    def content(self):
        if self.link_path not in self.file_system.file_system_nodes:
            raise LinkPathError
        else:
            if self.file_system.file_system_nodes[self.link_path].is_directory:
                raise LinkPathError
            else:
                return self.file_system.file_system_nodes[self.link_path].content

    def append(self, text):
        self.file_system.file_system_nodes[self.link_path].append(text)

    def truncate(self, text):
        self.file_system.file_system_nodes[self.link_path].truncate(text)


class FileSystemError(Exception):
    pass


class NodeDoesNotExistError(FileSystemError):
    pass


class DestinationNodeDoesNotExistError(NodeDoesNotExistError):
    pass


class SourceNodeDoesNotExistError(NodeDoesNotExistError):
    pass


class NotEnoughSpaceError(FileSystemError):
    pass


class DestinationNodeExistsError(FileSystemError):
    pass


class NonExplicitDirectoryDeletionError(FileSystemError):
    pass


class NonEmptyDirectoryDeletionError(FileSystemError):
    pass


class DestinationNotADirectoryError(FileSystemError):
    pass


class DirectoryHardLinkError(FileSystemError):
    pass


class FileSystemMountError(FileSystemError):
    pass


class MountPointNotADirectoryError(FileSystemMountError):
    pass


class MountPointDoesNotExistError(FileSystemMountError):
    pass


class MountPointNotEmptyError(FileSystemMountError):
    pass


class NotAMountpointError(FileSystemMountError):
    pass


class LinkPathError(FileSystemMountError):
    pass
