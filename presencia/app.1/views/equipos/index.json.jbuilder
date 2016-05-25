json.array!(@equipos) do |equipo|
  json.extract! equipo, :id, :nombre, :zona, :ip, :activo
  json.url equipo_url(equipo, format: :json)
end
