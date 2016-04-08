json.array!(@emails) do |email|
  json.extract! email, :id, :email, :password, :smtp_server, :puerto, :ssl
  json.url email_url(email, format: :json)
end
