#include "net/NetworkResult.hpp"

#include <QJsonDocument>

namespace chatterino
{
    NetworkResult::NetworkResult(const QByteArray& data)
        : data_(data)
    {
    }

    QJsonObject NetworkResult::parseJson() const
    {
        QJsonDocument jsonDoc(QJsonDocument::fromJson(this->data_));
        if (jsonDoc.isNull())
        {
            return QJsonObject{};
        }

        return jsonDoc.object();
    }

    const QByteArray& NetworkResult::getData() const
    {
        return this->data_;
    }
}  // namespace chatterino