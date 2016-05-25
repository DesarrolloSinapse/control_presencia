json.array!(@usuarios) do |usuario|
  json.extract! usuario, :id, :codigo, :nombre, :apellidos, :dni, :domicilio, :email, :centro, :dentro, :activo
  json.url usuario_url(usuario, format: :json)
end
