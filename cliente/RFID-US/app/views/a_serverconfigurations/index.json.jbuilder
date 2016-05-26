json.array!(@a_serverconfigurations) do |a_serverconfiguration|
  json.extract! a_serverconfiguration, :id, :ipdevice, :networkmask, :gateway, :url_server, :refreshtime
  json.url a_serverconfiguration_url(a_serverconfiguration, format: :json)
end
