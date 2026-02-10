#include <iostream>
#include <memory>

class DataSource
{
public:
    virtual void writeData(const std::string &data) = 0;
    virtual std::string readData() = 0;
    virtual ~DataSource() = default;
};

class FileDataSource : public DataSource
{
    std::string fileData;

public:
    void writeData(const std::string &data) override
    {
        fileData = data;
    }

    std::string readData() override
    {
        return fileData;
    }
};

class DataSourceDecorator : public DataSource
{
protected:
    std::unique_ptr<DataSource> wrappee;

public:
    DataSourceDecorator(std::unique_ptr<DataSource> src)
        : wrappee(std::move(src)) {}

    void writeData(const std::string &data) override
    {
        wrappee->writeData(data);
    }

    std::string readData() override
    {
        return wrappee->readData();
    }
};

class EncryptionDecorator : public DataSourceDecorator
{
public:
    using DataSourceDecorator::DataSourceDecorator;

    void writeData(const std::string &data) override
    {
        std::string encrypted = "[ENCRYPTED] " + data;
        wrappee->writeData(encrypted);
    }

    std::string readData() override
    {
        std::string data = wrappee->readData();
        return data + " (decrypted)";
    }
};

class CompressionDecorator : public DataSourceDecorator
{
public:
    using DataSourceDecorator::DataSourceDecorator;

    void writeData(const std::string &data) override
    {
        std::string compressed = "[COMPRESSED] " + data;
        wrappee->writeData(compressed);
    }

    std::string readData() override
    {
        std::string data = wrappee->readData();
        return data + " (decompressed)";
    }
};

int main()
{
    std::unique_ptr<DataSource> file =
        std::make_unique<FileDataSource>();

    // Add compression then encryption
    file = std::make_unique<CompressionDecorator>(std::move(file));
    file = std::make_unique<EncryptionDecorator>(std::move(file));

    file->writeData("Hello World");

    std::cout << file->readData() << "\n";
}
